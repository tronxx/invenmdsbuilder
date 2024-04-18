object frmDlgImpPenPag: TfrmDlgImpPenPag
  Left = 275
  Top = 407
  BorderStyle = bsDialog
  Caption = 'Reporte Pendientes de Pago'
  ClientHeight = 136
  ClientWidth = 549
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object RzPanel1: TPanel
    Left = 0
    Top = 0
    Width = 549
    Height = 136
    Align = alClient
    TabOrder = 0
    object RzLabel5: TLabel
      Left = 8
      Top = 5
      Width = 45
      Height = 13
      Caption = 'Ma&yorista'
      FocusControl = edtCveMay
    end
    object RzLabel4: TLabel
      Left = 8
      Top = 29
      Width = 45
      Height = 13
      Caption = 'Dirección'
      FocusControl = edtCveMay
    end
    object rlblLetrero: TLabel
      Left = 8
      Top = 98
      Width = 531
      Height = 33
      AutoSize = False
      Caption = 
        'Imprimir todos los  Mayoristas deje en blanco el codigo del mayo' +
        'rista y pulse el boton "Imprimir"'
      Color = clTeal
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      WordWrap = True
    end
    object lblAnio: TLabel
      Left = 28
      Top = 58
      Width = 22
      Height = 13
      Caption = 'Año:'
      FocusControl = edtCveMay
    end
    object edtCveMay: TEdit
      Left = 58
      Top = 3
      Width = 60
      Height = 21
      Hint = 'F4 Buscar'
      CharCase = ecUpperCase
      MaxLength = 4
      ParentShowHint = False
      ShowHint = True
      TabOrder = 0
      OnKeyDown = edtCveMayKeyDown
    end
    object edtMayorista: TEdit
      Left = 121
      Top = 3
      Width = 418
      Height = 21
      TabOrder = 1
    end
    object edtDirecc: TEdit
      Left = 58
      Top = 27
      Width = 481
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -9
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
    end
    object btnCerrar: TBitBtn
      Left = 439
      Top = 56
      Width = 100
      Height = 35
      Caption = '&Cerrar'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 5
      OnClick = btnCerrarClick
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        0400000000000001000000000000000000001000000010000000000000000000
        80000080000000808000800000008000800080800000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF0060FF00FF0088
        008868FF88FF88778877FF00FF00FF008800FF88FF88FF88778800FF00FF0007
        008888FF88FF8887887700000000770780008888888877878888666666070007
        8806666666878887888666666600000788066666668888878886666666088807
        8806666666888887888666666608880788066666668888878886660000000807
        0806668888888887F8866609999908078806668FFFFF88878886609999908807
        880668FFFFF888878886609099088807880668F8FF8888878886600090088807
        88066888F8888887888666600608888078066668868888887886666666088888
        0706666666888888878666666600000000066666668888888886}
      NumGlyphs = 2
    end
    object btnImpEdoCta: TBitBtn
      Left = 329
      Top = 56
      Width = 100
      Height = 35
      Caption = '&Imprimir'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 4
      OnClick = btnImpEdoCtaClick
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        0400000000000001000000000000000000001000000010000000000000000000
        80000080000000808000800000008000800080800000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00666666000666
        6666666666888666666666660078800666666666887888866666660077800880
        0666668877888888866660778878800880066877887888888886688877788880
        08066888777888888886887777788888800688777778888888868F7777F88888
        88808F7777F8888888888F77FF77788888808F77FF77788888888FFF77997778
        88808FFF7788777888888F77AA77788078808F77887778887888688F77788FF0
        7006688F77788FF8788666688F8FFFFF066666688F8FFFFF86666666688FFFFF
        F0666666688FFFFFF86666666668FFFFFF0066666668FFFFFF88666666668FFF
        8866666666668FFF886666666666688866666666666668886666}
      NumGlyphs = 2
    end
    object spinAnio: TdxSpinEdit
      Left = 59
      Top = 52
      Width = 71
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 3
      Value = 2005
    end
  end
  object qsMayoris: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select codigo, nombre, (direc || '#39' '#39' || ciu || '#39' '#39' || rfc) as Di' +
        'rec'
      'from mayoris where codigo = :codigo and cia = :cia')
    Left = 445
    Top = 8
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'codigo'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'cia'
        ParamType = ptUnknown
      end>
  end
end
