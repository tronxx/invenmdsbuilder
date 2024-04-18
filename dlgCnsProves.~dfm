object frmDlgConsProve: TfrmDlgConsProve
  Left = 291
  Top = 265
  BorderStyle = bsDialog
  Caption = 'Consulta de Proveedores'
  ClientHeight = 419
  ClientWidth = 420
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
    Width = 420
    Height = 67
    Align = alTop
    TabOrder = 0
    object RzLabel1: TLabel
      Left = 8
      Top = 8
      Width = 27
      Height = 13
      Caption = 'Cla&ve'
      FocusControl = edtClave
    end
    object RzLabel2: TLabel
      Left = 11
      Top = 39
      Width = 37
      Height = 13
      Caption = '&Nombre'
      FocusControl = edtNombre
    end
    object edtClave: TEdit
      Left = 53
      Top = 6
      Width = 58
      Height = 21
      CharCase = ecUpperCase
      MaxLength = 4
      TabOrder = 0
    end
    object edtNombre: TEdit
      Left = 53
      Top = 37
      Width = 259
      Height = 21
      CharCase = ecUpperCase
      TabOrder = 1
      OnKeyDown = edtNombreKeyDown
    end
    object btnEjecutar: TBitBtn
      Left = 318
      Top = 3
      Width = 87
      Height = 28
      Caption = '&Ejecutar'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
      OnClick = btnEjecutarClick
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        0400000000000001000000000000000000001000000010000000000000000000
        80000080000000808000800000008000800080800000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00666663666666
        6666666668666666666666666306666666666666688666666666666666306666
        666666666688666666666666663B06666666666666878666666666663000F066
        666666668888F866666666663FBFBF06666666668F7F7F866666666663FB0333
        6666666668F788886666666663BFB06666666666687F786666666630000BFB06
        666666888887F7866666663FBFBFBFB06666668F7F7F7F7866666663FBFB0333
        66666668F7F7888866666663BFBFB066666666687F7F7866666666663BFBFB06
        6666666687F7F786666666663FBFBFB0666666668F7F7F786666666663FBFBFB
        0666666668F7F7F7866666666333333333666666688888888866}
      NumGlyphs = 2
    end
    object btnCerrar: TBitBtn
      Left = 318
      Top = 35
      Width = 87
      Height = 28
      Caption = '&Cerrar'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 3
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
    object chkColumnas: TCheckBox
      Left = 128
      Top = 8
      Width = 100
      Height = 17
      Caption = 'Todos los Datos'
      TabOrder = 4
      OnClick = chkColumnasClick
    end
  end
  object dxDBGrid1: TdxDBGrid
    Left = 0
    Top = 67
    Width = 420
    Height = 352
    Bands = <
      item
      end>
    DefaultLayout = True
    HeaderPanelRowCount = 1
    KeyField = 'CODIGO'
    SummaryGroups = <>
    SummarySeparator = ', '
    Align = alClient
    TabOrder = 1
    OnKeyDown = dxDBGrid1KeyDown
    DataSource = dtsNombre
    Filter.Criteria = {00000000}
    LookAndFeel = lfFlat
    OptionsBehavior = [edgoAutoSort, edgoDragScroll, edgoEnterShowEditor, edgoImmediateEditor, edgoTabThrough, edgoVertThrough]
    OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseBookmarks]
    OptionsView = [edgoBandHeaderWidth, edgoIndicator, edgoRowSelect, edgoUseBitmap]
    object dxDBGrid1CODIGO: TdxDBGridMaskColumn
      Caption = 'Clave'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'CODIGO'
    end
    object dxDBGrid1NOMBRE: TdxDBGridMaskColumn
      Caption = 'Nombre del Proveedor'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'NOMBRE'
    end
    object dxDBGrid1DIREC: TdxDBGridMaskColumn
      Visible = False
      BandIndex = 0
      RowIndex = 0
      FieldName = 'DIREC'
    end
    object dxDBGrid1CIU: TdxDBGridMaskColumn
      Visible = False
      BandIndex = 0
      RowIndex = 0
      FieldName = 'CIU'
    end
    object dxDBGrid1RFC: TdxDBGridMaskColumn
      Visible = False
      BandIndex = 0
      RowIndex = 0
      FieldName = 'RFC'
    end
    object dxDBGrid1TEL: TdxDBGridMaskColumn
      Visible = False
      BandIndex = 0
      RowIndex = 0
      FieldName = 'TEL'
    end
    object dxDBGrid1CARGOS: TdxDBGridMaskColumn
      Visible = False
      BandIndex = 0
      RowIndex = 0
      FieldName = 'CARGOS'
    end
    object dxDBGrid1ABONOS: TdxDBGridMaskColumn
      Visible = False
      BandIndex = 0
      RowIndex = 0
      FieldName = 'ABONOS'
    end
    object dxDBGrid1COMPRAANU: TdxDBGridMaskColumn
      Visible = False
      BandIndex = 0
      RowIndex = 0
      FieldName = 'COMPRAANU'
    end
    object dxDBGrid1COMPRAMES: TdxDBGridMaskColumn
      Visible = False
      BandIndex = 0
      RowIndex = 0
      FieldName = 'COMPRAMES'
    end
    object dxDBGrid1LIMITE: TdxDBGridMaskColumn
      Visible = False
      BandIndex = 0
      RowIndex = 0
      FieldName = 'LIMITE'
    end
    object dxDBGrid1CONTACTO: TdxDBGridMaskColumn
      Visible = False
      BandIndex = 0
      RowIndex = 0
      FieldName = 'CONTACTO'
    end
    object dxDBGrid1ULTMOV: TdxDBGridMaskColumn
      Visible = False
      BandIndex = 0
      RowIndex = 0
      FieldName = 'ULTMOV'
    end
    object dxDBGrid1STATUS: TdxDBGridMaskColumn
      Visible = False
      BandIndex = 0
      RowIndex = 0
      FieldName = 'STATUS'
    end
    object dxDBGrid1CIA: TdxDBGridMaskColumn
      Visible = False
      BandIndex = 0
      RowIndex = 0
      FieldName = 'CIA'
    end
  end
  object qsNombre: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'Select * from proveedor'
      'Where CIA = :Cia and ((Nombre like :Nombre) Or Codigo = :Codigo)'
      'order by nombre')
    Left = 80
    Top = 80
    ParamData = <
      item
        DataType = ftInteger
        Name = 'Cia'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'Nombre'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'Codigo'
        ParamType = ptUnknown
      end>
    object qsNombreCODIGO: TStringField
      FieldName = 'CODIGO'
      Origin = 'MANVEHI.PROVEEDOR.CODIGO'
      Size = 4
    end
    object qsNombreNOMBRE: TStringField
      FieldName = 'NOMBRE'
      Origin = 'MANVEHI.PROVEEDOR.NOMBRE'
      Size = 50
    end
    object qsNombreDIREC: TStringField
      FieldName = 'DIREC'
      Origin = 'MANVEHI.PROVEEDOR.DIREC'
      Size = 50
    end
    object qsNombreCIU: TStringField
      FieldName = 'CIU'
      Origin = 'MANVEHI.PROVEEDOR.CIU'
      Size = 30
    end
    object qsNombreRFC: TStringField
      FieldName = 'RFC'
      Origin = 'MANVEHI.PROVEEDOR.RFC'
      Size = 15
    end
    object qsNombreTEL: TStringField
      FieldName = 'TEL'
      Origin = 'MANVEHI.PROVEEDOR.TEL'
    end
    object qsNombreCARGOS: TFloatField
      FieldName = 'CARGOS'
      Origin = 'MANVEHI.PROVEEDOR.CARGOS'
    end
    object qsNombreABONOS: TFloatField
      FieldName = 'ABONOS'
      Origin = 'MANVEHI.PROVEEDOR.ABONOS'
    end
    object qsNombreCOMPRAANU: TFloatField
      FieldName = 'COMPRAANU'
      Origin = 'MANVEHI.PROVEEDOR.COMPRAANU'
    end
    object qsNombreCOMPRAMES: TFloatField
      FieldName = 'COMPRAMES'
      Origin = 'MANVEHI.PROVEEDOR.COMPRAMES'
    end
    object qsNombreLIMITE: TFloatField
      FieldName = 'LIMITE'
      Origin = 'MANVEHI.PROVEEDOR.LIMITE'
    end
    object qsNombreCONTACTO: TStringField
      FieldName = 'CONTACTO'
      Origin = 'MANVEHI.PROVEEDOR.CONTACTO'
      Size = 30
    end
    object qsNombreULTMOV: TIntegerField
      FieldName = 'ULTMOV'
      Origin = 'MANVEHI.PROVEEDOR.ULTMOV'
    end
    object qsNombreSTATUS: TStringField
      FieldName = 'STATUS'
      Origin = 'MANVEHI.PROVEEDOR.STATUS'
      FixedChar = True
      Size = 1
    end
    object qsNombreCIA: TSmallintField
      FieldName = 'CIA'
      Origin = 'MANVEHI.PROVEEDOR.CIA'
    end
  end
  object dtsNombre: TDataSource
    DataSet = qsNombre
    Left = 88
    Top = 112
  end
end
