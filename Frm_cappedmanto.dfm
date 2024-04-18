object frmDlgCapPed: TfrmDlgCapPed
  Left = 308
  Top = 198
  BorderStyle = bsDialog
  Caption = 'Captura de Pedidos'
  ClientHeight = 485
  ClientWidth = 632
  Color = clBtnFace
  Constraints.MinHeight = 480
  Constraints.MinWidth = 640
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object pnlPedido: TPanel
    Left = 0
    Top = 0
    Width = 632
    Height = 128
    Align = alTop
    TabOrder = 0
    object RzLabel1: TLabel
      Left = 17
      Top = 16
      Width = 36
      Height = 13
      Caption = '&Periodo'
    end
    object RzLabel2: TLabel
      Left = 142
      Top = 16
      Width = 37
      Height = 13
      Caption = '&Numero'
    end
    object RzLabel3: TLabel
      Left = 294
      Top = 16
      Width = 30
      Height = 13
      Caption = '&Fecha'
    end
    object RzLabel4: TLabel
      Left = 457
      Top = 16
      Width = 35
      Height = 13
      Caption = 'Importe'
    end
    object RzLabel5: TLabel
      Left = 463
      Top = 48
      Width = 29
      Height = 13
      Caption = 'I  V  A'
    end
    object RzLabel6: TLabel
      Left = 456
      Top = 80
      Width = 36
      Height = 13
      Caption = 'T o t a l'
    end
    object RzLabel7: TLabel
      Left = 4
      Top = 48
      Width = 49
      Height = 13
      Caption = 'Pro&veedor'
    end
    object RzLabel8: TLabel
      Left = 9
      Top = 77
      Width = 43
      Height = 13
      Caption = 'Contacto'
    end
    object RzLabel9: TLabel
      Left = 248
      Top = 80
      Width = 26
      Height = 13
      Caption = 'Plazo'
    end
    object RzLabel15: TLabel
      Left = 19
      Top = 104
      Width = 33
      Height = 13
      Caption = 'Estado'
    end
    object RzLabel16: TLabel
      Left = 240
      Top = 104
      Width = 33
      Height = 13
      Caption = 'Pedido'
    end
    object edtImporte: TdxCurrencyEdit
      Left = 499
      Top = 12
      Width = 105
      TabOrder = 8
      TabStop = False
      ReadOnly = True
      DisplayFormat = '0.00;(0.00)'
      StoredValues = 64
    end
    object edtIva: TdxCurrencyEdit
      Left = 499
      Top = 44
      Width = 105
      TabOrder = 9
      TabStop = False
      ReadOnly = True
      DisplayFormat = '0.00;(0.00)'
      StoredValues = 64
    end
    object edtTotal: TdxCurrencyEdit
      Left = 499
      Top = 76
      Width = 105
      TabOrder = 10
      TabStop = False
      ReadOnly = True
      DisplayFormat = '0.00;(0.00)'
      StoredValues = 64
    end
    object edtPeriodo: TEdit
      Left = 57
      Top = 12
      Width = 55
      Height = 21
      MaxLength = 3
      TabOrder = 0
    end
    object edtNumero: TEdit
      Left = 185
      Top = 12
      Width = 72
      Height = 21
      TabOrder = 1
      OnKeyDown = edtNumeroKeyDown
    end
    object dtFecha: TDateTimePicker
      Left = 333
      Top = 12
      Width = 98
      Height = 21
      CalAlignment = dtaLeft
      Date = 38642.7295020833
      Time = 38642.7295020833
      DateFormat = dfShort
      DateMode = dmComboBox
      Kind = dtkDate
      ParseInput = False
      TabOrder = 2
    end
    object edtProve: TEdit
      Left = 57
      Top = 45
      Width = 63
      Height = 21
      Hint = 'F4 Buscar Prove.'
      CharCase = ecUpperCase
      MaxLength = 4
      ParentShowHint = False
      ShowHint = True
      TabOrder = 3
      OnExit = edtProveExit
      OnKeyDown = edtProveKeyDown
    end
    object edtNomPro: TEdit
      Left = 123
      Top = 45
      Width = 306
      Height = 21
      TabStop = False
      CharCase = ecUpperCase
      ReadOnly = True
      TabOrder = 4
    end
    object edtContacto: TEdit
      Left = 57
      Top = 74
      Width = 172
      Height = 21
      CharCase = ecUpperCase
      MaxLength = 30
      TabOrder = 5
      OnExit = edtContactoExit
    end
    object edtPlazo: TEdit
      Left = 281
      Top = 76
      Width = 148
      Height = 21
      CharCase = ecUpperCase
      MaxLength = 10
      TabOrder = 6
    end
    object lblEstado: TEdit
      Left = 57
      Top = 101
      Width = 171
      Height = 21
      TabStop = False
      CharCase = ecUpperCase
      ReadOnly = True
      TabOrder = 11
    end
    object edtPorcIva: TdxCurrencyEdit
      Left = 385
      Top = 101
      Width = 45
      TabOrder = 12
      TabStop = False
      Visible = False
      ReadOnly = True
      DisplayFormat = '0;(0)'
      StoredValues = 64
    end
    object cmbPedido: TComboBox
      Left = 282
      Top = 100
      Width = 47
      Height = 21
      Ctl3D = False
      ItemHeight = 13
      ParentCtl3D = False
      TabOrder = 7
      Text = 'SI'
      Items.Strings = (
        'SI'
        'NO')
    end
  end
  object grpRenglon: TGroupBox
    Left = 0
    Top = 128
    Width = 632
    Height = 144
    Align = alTop
    Caption = '&Datos del Renglon'
    Color = cl3DLight
    ParentColor = False
    TabOrder = 1
    object RzLabel10: TLabel
      Left = 21
      Top = 24
      Width = 42
      Height = 13
      Caption = 'Can&tidad'
    end
    object RzLabel11: TLabel
      Left = 30
      Top = 46
      Width = 33
      Height = 13
      Caption = 'Codigo'
    end
    object RzLabel12: TLabel
      Left = 27
      Top = 67
      Width = 36
      Height = 13
      Caption = 'Descri.:'
    end
    object RzLabel13: TLabel
      Left = 137
      Top = 89
      Width = 41
      Height = 13
      Caption = 'Costo U.'
    end
    object RzLabel14: TLabel
      Left = 268
      Top = 89
      Width = 24
      Height = 13
      Caption = 'Total'
    end
    object RzLabel17: TLabel
      Left = 5
      Top = 111
      Width = 55
      Height = 13
      Caption = 'Precio Lista'
    end
    object RzLabel18: TLabel
      Left = 175
      Top = 112
      Width = 24
      Height = 13
      Caption = 'MUB'
    end
    object RzLabel19: TLabel
      Left = 244
      Top = 43
      Width = 18
      Height = 16
      Caption = 'F4'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object RzLabel20: TLabel
      Left = 28
      Top = 89
      Width = 26
      Height = 13
      Caption = '% Iva'
    end
    object edtCantidad: TdxCurrencyEdit
      Left = 66
      Top = 19
      Width = 65
      TabOrder = 0
      OnChange = edtCantidadChange
      DisplayFormat = '0.00;(0.00)'
      StoredValues = 0
    end
    object edtCodigo: TEdit
      Left = 66
      Top = 41
      Width = 175
      Height = 21
      CharCase = ecUpperCase
      TabOrder = 1
      OnChange = edtCodigoChange
      OnKeyDown = edtCodigoKeyDown
    end
    object edtDescri: TEdit
      Left = 66
      Top = 63
      Width = 316
      Height = 21
      CharCase = ecUpperCase
      TabOrder = 2
      OnExit = edtDescriExit
    end
    object edtCosto: TdxCurrencyEdit
      Left = 181
      Top = 85
      Width = 78
      TabOrder = 4
      OnChange = edtCostoChange
      DisplayFormat = '0.00;(0.00)'
      StoredValues = 0
    end
    object edtTotRen: TdxCurrencyEdit
      Left = 300
      Top = 85
      Width = 82
      TabOrder = 5
      DisplayFormat = '0.00;(0.00)'
      StoredValues = 0
    end
    object btnNuevo: TBitBtn
      Left = 424
      Top = 68
      Width = 90
      Height = 30
      Caption = 'N&uevo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 7
      OnClick = btnNuevoClick
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        0400000000000001000000000000000000001000000010000000000000000000
        80000080000000808000800000008000800080800000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF006F6FF6666666
        66666666666666666666FFFFFFF6666666666666666666666666FFFFF8111666
        66666666668886666666FFFF8911116666666666688888666666FFFF91911116
        66666666888888866666F6F61999111066666666878888886666666691919108
        0666666688788888866666666919103780666666688788878866666666910BB3
        7806666666888778788666666663BF7B3780666666687F778788666666663BF7
        B3036666666687F778886666666663BFB03366666666687F788866666666663B
        37B366666666668787786666666666637BBB6666666666687777666666666666
        3FBB6666666666668F7766666666666663FB66666666666668F7}
      NumGlyphs = 2
    end
    object btnAgregar: TBitBtn
      Left = 424
      Top = 102
      Width = 90
      Height = 30
      Caption = 'Agrega&r'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 6
      OnClick = btnAgregarClick
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        0400000000000001000000000000000000001000000010000000000000000000
        80000080000000808000800000008000800080800000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00666666666666
        6666666666666666666666000000000000066688888888888886604407447770
        4406688887FF777888866044074477704406688887FF77788886604407447770
        4406688887FF7778888660444777777444066888877777788886604444444444
        44066888888888888886604400000000440668888888888888866040FFFFFFFF
        04066888FFFFFFFF88866040FFFFFFFF04066888FFFFFFFF88866040F888888F
        04066888F888888F88866040FFFFFFFF04066888FFFFFFFF88866070F888888F
        00066878F888888F88866040FFFFFFFF04066888FFFFFFFF8886600000000000
        0006688888888888888666666666666666666666666666666666}
      NumGlyphs = 2
    end
    object edtPrecLista: TdxCurrencyEdit
      Left = 66
      Top = 107
      Width = 79
      TabOrder = 8
      TabStop = False
      ReadOnly = True
      DisplayFormat = '0.00;(0.00)'
      StoredValues = 64
    end
    object edtMub: TdxCurrencyEdit
      Left = 202
      Top = 107
      Width = 57
      TabOrder = 9
      TabStop = False
      ReadOnly = True
      DisplayFormat = '0.00;(0.00)'
      StoredValues = 64
    end
    object dxDBGrid1: TdxDBGrid
      Left = 523
      Top = 15
      Width = 107
      Height = 127
      TabStop = False
      Bands = <
        item
        end>
      DefaultLayout = True
      HeaderPanelRowCount = 1
      KeyField = 'ALM'
      ShowSummaryFooter = True
      SummaryGroups = <>
      SummarySeparator = ', '
      Align = alRight
      Color = cl3DLight
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -9
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 10
      BandFont.Charset = DEFAULT_CHARSET
      BandFont.Color = clWindowText
      BandFont.Height = -11
      BandFont.Name = 'MS Sans Serif'
      BandFont.Style = []
      DataSource = dtsExistencias
      Filter.Criteria = {00000000}
      HeaderFont.Charset = DEFAULT_CHARSET
      HeaderFont.Color = clWindowText
      HeaderFont.Height = -11
      HeaderFont.Name = 'MS Sans Serif'
      HeaderFont.Style = []
      LookAndFeel = lfUltraFlat
      OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoUseBookmarks]
      PreviewFont.Charset = DEFAULT_CHARSET
      PreviewFont.Color = clBlue
      PreviewFont.Height = -11
      PreviewFont.Name = 'MS Sans Serif'
      PreviewFont.Style = []
      object dxDBGrid1ALM: TdxDBGridMaskColumn
        Alignment = taCenter
        Caption = 'Alm'
        Width = 40
        BandIndex = 0
        RowIndex = 0
        FieldName = 'ALM'
      end
      object dxDBGrid1EXISTENCIA: TdxDBGridMaskColumn
        Alignment = taCenter
        Caption = 'Exist.'
        Width = 47
        BandIndex = 0
        RowIndex = 0
        FieldName = 'EXISTENCIA'
        SummaryFooterType = cstSum
        SummaryFooterField = 'EXISTENCIA'
        SummaryFooterFormat = '0'
      end
    end
    object edtIvaRen: TdxCurrencyEdit
      Left = 66
      Top = 85
      Width = 55
      Enabled = False
      TabOrder = 3
      DisplayFormat = '0;(0)'
      StoredValues = 0
    end
  end
  object dbgrdReng: TdxDBGrid
    Left = 0
    Top = 272
    Width = 632
    Height = 176
    Bands = <
      item
      end>
    DefaultLayout = True
    HeaderPanelRowCount = 1
    KeyField = 'CONSE'
    ShowSummaryFooter = True
    SummaryGroups = <>
    SummarySeparator = ', '
    Align = alClient
    TabOrder = 2
    DataSource = dtsRenEntra
    Filter.Criteria = {00000000}
    LookAndFeel = lfUltraFlat
    OptionsBehavior = [edgoAutoSort, edgoDragScroll, edgoEnterShowEditor, edgoImmediateEditor, edgoMultiSort, edgoTabThrough, edgoVertThrough]
    OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoSyncSelection, edgoUseBookmarks]
    object dbgrdRengTIPO: TdxDBGridMaskColumn
      Visible = False
      Width = 43
      BandIndex = 0
      RowIndex = 0
      FieldName = 'TIPO'
    end
    object dbgrdRengALM: TdxDBGridMaskColumn
      Visible = False
      Width = 41
      BandIndex = 0
      RowIndex = 0
      FieldName = 'ALM'
    end
    object dbgrdRengRECEMI: TdxDBGridMaskColumn
      Visible = False
      Width = 68
      BandIndex = 0
      RowIndex = 0
      FieldName = 'RECEMI'
    end
    object dbgrdRengNUMERO: TdxDBGridMaskColumn
      Visible = False
      Width = 92
      BandIndex = 0
      RowIndex = 0
      FieldName = 'NUMERO'
    end
    object dbgrdRengCONSE: TdxDBGridMaskColumn
      Alignment = taCenter
      Caption = 'Ren.#'
      Visible = False
      Width = 43
      BandIndex = 0
      RowIndex = 0
      FieldName = 'CONSE'
    end
    object dbgrdRengCODINV: TdxDBGridMaskColumn
      Caption = 'Código'
      Width = 108
      BandIndex = 0
      RowIndex = 0
      FieldName = 'CODINV'
    end
    object dbgrdRengSERIE: TdxDBGridMaskColumn
      Visible = False
      Width = 178
      BandIndex = 0
      RowIndex = 0
      FieldName = 'SERIE'
    end
    object dbgrdRengDESCRI: TdxDBGridColumn
      Caption = 'Descripción del Producto'
      Width = 230
      BandIndex = 0
      RowIndex = 0
      FieldName = 'SCONCEPTO'
    end
    object dbgrdRengSIONO: TdxDBGridMaskColumn
      Alignment = taCenter
      Caption = 'S/N'
      Visible = False
      Width = 30
      BandIndex = 0
      RowIndex = 0
      FieldName = 'SIONO'
    end
    object dbgrdRengFOLSAL: TdxDBGridMaskColumn
      Visible = False
      Width = 92
      BandIndex = 0
      RowIndex = 0
      FieldName = 'FOLSAL'
    end
    object dbgrdRengFOLENT: TdxDBGridMaskColumn
      Visible = False
      Width = 92
      BandIndex = 0
      RowIndex = 0
      FieldName = 'FOLENT'
    end
    object dbgrdRengUNIDS: TdxDBGridCurrencyColumn
      Caption = 'Unidades'
      Width = 51
      BandIndex = 0
      RowIndex = 0
      FieldName = 'UNIDS'
      DisplayFormat = '0.00;-0.00'
    end
    object dbgrdRengCOSTOU: TdxDBGridCurrencyColumn
      Caption = 'Costo Unit.'
      Width = 89
      BandIndex = 0
      RowIndex = 0
      FieldName = 'COSTOU'
    end
    object dbgrdRengIMPORTE: TdxDBGridCurrencyColumn
      Caption = 'Importe'
      Width = 95
      BandIndex = 0
      RowIndex = 0
      FieldName = 'IMPORTE'
    end
    object dbgrdRengPIVA: TdxDBGridCurrencyColumn
      Alignment = taCenter
      Caption = '%Iva'
      Visible = False
      Width = 51
      BandIndex = 0
      RowIndex = 0
      FieldName = 'PIVA'
      DisplayFormat = '0.00;-0.00'
    end
    object dbgrdRengCANTMUEVE: TdxDBGridMaskColumn
      Visible = False
      Width = 104
      BandIndex = 0
      RowIndex = 0
      FieldName = 'CANTMUEVE'
    end
    object dbgrdRengSTATUS: TdxDBGridMaskColumn
      Visible = False
      Width = 71
      BandIndex = 0
      RowIndex = 0
      FieldName = 'STATUS'
    end
    object dbgrdRengPERSENVREC: TdxDBGridMaskColumn
      Visible = False
      Width = 114
      BandIndex = 0
      RowIndex = 0
      FieldName = 'PERSENVREC'
    end
    object dbgrdRengCIA: TdxDBGridMaskColumn
      Visible = False
      Width = 92
      BandIndex = 0
      RowIndex = 0
      FieldName = 'CIA'
    end
    object dbgrdRengVEND: TdxDBGridMaskColumn
      Visible = False
      Width = 51
      BandIndex = 0
      RowIndex = 0
      FieldName = 'VEND'
    end
    object dbgrdRengPOBLAC: TdxDBGridMaskColumn
      Visible = False
      Width = 92
      BandIndex = 0
      RowIndex = 0
      FieldName = 'POBLAC'
    end
    object dbgrdRengTIPAGO: TdxDBGridMaskColumn
      Visible = False
      Width = 67
      BandIndex = 0
      RowIndex = 0
      FieldName = 'TIPAGO'
    end
    object dbgrdRengPRVTA: TdxDBGridMaskColumn
      Visible = False
      Width = 92
      BandIndex = 0
      RowIndex = 0
      FieldName = 'PRVTA'
    end
    object dbgrdRengENTOSAL: TdxDBGridMaskColumn
      Visible = False
      Width = 81
      BandIndex = 0
      RowIndex = 0
      FieldName = 'ENTOSAL'
    end
    object dbgrdRengENTCAN: TdxDBGridMaskColumn
      Visible = False
      Width = 72
      BandIndex = 0
      RowIndex = 0
      FieldName = 'ENTCAN'
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 448
    Width = 632
    Height = 37
    Align = alBottom
    TabOrder = 3
    object btnObserva: TBitBtn
      Left = 27
      Top = 4
      Width = 90
      Height = 30
      Caption = 'Observ'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      OnClick = btnObservaClick
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        0400000000000001000000000000000000001000000010000000000000000000
        80000080000000808000800000008000800080800000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00666666666666
        6666666666666666666600000000000066668888888888886666877777777770
        666687777777777866668FFFFFFFFF7066668FFFFFFFFF7866668F44F4444F70
        66668F88F8888F7866668FFFFFFFFF7066668FFFFFFFFF7866668F44F4444F70
        66668F88F8888F7866668FFFFFFFFF7066668FFFFFFFFF7866668FFFFFFF0F70
        66668FFFFFFF8F7866668F00FFF0B07066648F88FFF8787866688F0F0F0B0F00
        06448F8F8F878F8886888FF0B0B0F0FBF0448FF87878F8F7F88888880F0F0FBF
        BF4488888F8F8F7F7F88666660B0FBFBFB4466666878F7F7F7886666660FBFBF
        B0446666668F7F7F788866666660000006446666666888888688}
      NumGlyphs = 2
    end
    object btnGuardar: TBitBtn
      Left = 424
      Top = 4
      Width = 90
      Height = 30
      Caption = '&Guardar'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      OnClick = btnGuardarClick
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        0400000000000001000000000000000000001000000010000000000000000000
        80000080000000808000800000008000800080800000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00666666666666
        6666666666666666666666000000000000066688888888888886604407447770
        4406688887FF777888866044074477704406688887FF77788886604407447770
        4406688887FF7778888660444777777444066888877777788886604444444444
        44066888888888888886604400000000440668888888888888866040FFFFFFFF
        04066888FFFFFFFF88866040FFFFFFFF04066888FFFFFFFF88866040F888888F
        04066888F888888F88866040FFFFFFFF04066888FFFFFFFF88866070F888888F
        00066878F888888F88866040FFFFFFFF04066888FFFFFFFF8886600000000000
        0006688888888888888666666666666666666666666666666666}
      NumGlyphs = 2
    end
    object btnCerrar: TBitBtn
      Left = 531
      Top = 4
      Width = 90
      Height = 30
      Caption = '&Cerrar'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
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
  end
  object qsAnios: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select * from periodoent '
      'where anio = :anio')
    Left = 517
    Top = 96
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'anio'
        ParamType = ptUnknown
      end>
  end
  object qsMaxPed: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select max(numero) as UltNumero from entradas where tipo=:Tipo a' +
        'nd alm= :Almac and cia= :Cia')
    Left = 552
    Top = 96
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'Tipo'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'Almac'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
  object qsPedido: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select a.tipo, a.alm, a.numero, a.facpro, a.prove, a.perenvrec, '
      'a.status,'
      
        'cast((case a.status when '#39'A'#39' then '#39'ABIERTO'#39'  when '#39'C'#39' then '#39'CERR' +
        'ADO'#39' end) as varchar(12) )'
      'as sStatus,'
      'a.coniva, a.fecha, a.importe, a.iva, (a.importe+a.iva) as total,'
      ' b.Nombre as sNomProve, c.Nombre as sNomUsu,'
      'd.concepto'
      'from entradas a '
      'left outer join proveedor b on b.codigo = a.prove'
      'left outer join usuarios c on c.iniciales = a.usuario'
      'left outer join conceps d on d.ncon = a.perenvrec'
      
        'where a.numero = :Numero and a.alm = :Almac and a.Tipo = :Tipo a' +
        'nd a.cia = :Cia'
      '')
    Left = 488
    Top = 96
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'Numero'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'Almac'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'Tipo'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
  object qsProve: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select codigo, nombre from proveedor where codigo = :Prove and c' +
        'ia = :Cia')
    Left = 600
    Top = 192
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'Prove'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
  object qsRenentra: TQuery
    CachedUpdates = True
    AfterOpen = qsRenentraAfterOpen
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select a.*, b.Descri, c.Concepto, cast('#39#39' as varchar(30)) as sCo' +
        'ncepto '
      'from RenEntra a'
      'left outer join inven b on a.codinv = b.codigo and a.cia = b.cia'
      'left outer join conceps c on c.ncon = a.persenvrec'
      
        'where a.Numero = :Numero and a.alm = :almac and a.Tipo = :Tipo a' +
        'nd a.cia = :Cia')
    UpdateObject = upsqlRenEntra
    Left = 32
    Top = 328
    ParamData = <
      item
        DataType = ftInteger
        Name = 'Numero'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'almac'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'Tipo'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
  object dtsRenEntra: TDataSource
    DataSet = qsRenentra
    Left = 72
    Top = 328
  end
  object qsCodInv: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select codigo, cod2, descri, costos, coston, precio, piva'
      ' from inven where codigo = :Codigo and Cia = :Cia')
    Left = 112
    Top = 192
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'Codigo'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
  object upsqlRenEntra: TUpdateSQL
    ModifySQL.Strings = (
      'update RenEntra'
      'set'
      '  TIPO = :TIPO,'
      '  ALM = :ALM,'
      '  RECEMI = :RECEMI,'
      '  NUMERO = :NUMERO,'
      '  CONSE = :CONSE,'
      '  CODINV = :CODINV,'
      '  SERIE = :SERIE,'
      '  SIONO = :SIONO,'
      '  FOLSAL = :FOLSAL,'
      '  FOLENT = :FOLENT,'
      '  UNIDS = :UNIDS,'
      '  COSTOU = :COSTOU,'
      '  PIVA = :PIVA,'
      '  IMPORTE = :IMPORTE,'
      '  CANTMUEVE = :CANTMUEVE,'
      '  STATUS = :STATUS,'
      '  PERSENVREC = :PERSENVREC,'
      '  CIA = :CIA,'
      '  VEND = :VEND,'
      '  POBLAC = :POBLAC,'
      '  TIPAGO = :TIPAGO,'
      '  PRVTA = :PRVTA,'
      '  ENTOSAL = :ENTOSAL,'
      '  ENTCAN = :ENTCAN'
      'where'
      '  TIPO = :OLD_TIPO and'
      '  ALM = :OLD_ALM and'
      '  RECEMI = :OLD_RECEMI and'
      '  NUMERO = :OLD_NUMERO and'
      '  CONSE = :OLD_CONSE and'
      '  CODINV = :OLD_CODINV')
    InsertSQL.Strings = (
      'insert into RenEntra'
      
        '  (TIPO, ALM, RECEMI, NUMERO, CONSE, CODINV, SERIE, SIONO, FOLSA' +
        'L, '
      'FOLENT, '
      
        '   UNIDS, COSTOU, PIVA, IMPORTE, CANTMUEVE, STATUS, PERSENVREC, ' +
        'CIA, '
      'VEND, '
      '   POBLAC, TIPAGO, PRVTA, ENTOSAL, ENTCAN)'
      'values'
      
        '  (:TIPO, :ALM, :RECEMI, :NUMERO, :CONSE, :CODINV, :SERIE, :SION' +
        'O, :FOLSAL, '
      
        '   :FOLENT, :UNIDS, :COSTOU, :PIVA, :IMPORTE, :CANTMUEVE, :STATU' +
        'S, '
      ':PERSENVREC, '
      '   :CIA, :VEND, :POBLAC, :TIPAGO, :PRVTA, :ENTOSAL, :ENTCAN)')
    DeleteSQL.Strings = (
      'delete from RenEntra'
      'where'
      '  TIPO = :OLD_TIPO and'
      '  ALM = :OLD_ALM and'
      '  RECEMI = :OLD_RECEMI and'
      '  NUMERO = :OLD_NUMERO and'
      '  CONSE = :OLD_CONSE and'
      '  CODINV = :OLD_CODINV')
    Left = 72
    Top = 362
  end
  object qsMaxReng: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select max(conse)+1 as Siguiente from RenEntra '
      
        'where Numero = :Numero and alm = :almac and Tipo = :Tipo and cia' +
        ' = :Cia')
    Left = 112
    Top = 328
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'Numero'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'almac'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'Tipo'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
  object qsExistencias: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select alm,existes+existen as Existencia '
      
        'from exist, almacen where codigo= :Codigo and alm=clave and alma' +
        'cen.cia=exist.cia'
      'and exist.cia=:Cia')
    Left = 560
    Top = 168
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'Codigo'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
  object dtsExistencias: TDataSource
    DataSet = qsExistencias
    Left = 560
    Top = 208
  end
  object qiPedido: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'insert into Entradas'
      
        '  (TIPO, ALM, RECEMI, NUMERO, FACPRO, PROVE, PERENVREC, STATUS, ' +
        'CONIVA, '
      
        '   FECHA, IMPORTE, IVA, TOTAL, VENCE, CTOFIN, TASCOMP, TASPRO, F' +
        'ECHAFAC, '
      
        '   LETRAS, PLAZOCFP, PLANP, FLETES, DESXAP, FECHAPRP, CTOFINCOMP' +
        ', USUARIO,  CIA)'
      'values'
      
        '  (:TIPO, :ALM, :RECEMI, :NUMERO, :FACPRO, :PROVE, :PERENVREC, :' +
        'STATUS, '
      
        '   :CONIVA, :FECHA, :IMPORTE, :IVA, :TOTAL, :VENCE, :CTOFIN, :TA' +
        'SCOMP, '
      
        '   :TASPRO, :FECHAFAC, :LETRAS, :PLAZOCFP, :PLANP, :FLETES, :DES' +
        'XAP, :FECHAPRP, '
      '   :CTOFINCOMP, :USUARIO, :CIA)'
      '')
    Left = 152
    Top = 328
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'TIPO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ALM'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'RECEMI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'NUMERO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FACPRO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'PROVE'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'PERENVREC'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'STATUS'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CONIVA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FECHA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'IMPORTE'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'IVA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'TOTAL'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'VENCE'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CTOFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'TASCOMP'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'TASPRO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FECHAFAC'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'LETRAS'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'PLAZOCFP'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'PLANP'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FLETES'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'DESXAP'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FECHAPRP'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CTOFINCOMP'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'USUARIO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qsConcepto: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select * from conceps where rtrim(concepto) = :concepto')
    Left = 192
    Top = 328
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'concepto'
        ParamType = ptUnknown
      end>
  end
  object qsMaxConcep: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select max(ncon) as Ultimo from conceps')
    Left = 224
    Top = 328
  end
  object qiConceps: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'insert into conceps (concepto,ncon) values (:Concepto, :ncon)')
    Left = 256
    Top = 328
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'Concepto'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ncon'
        ParamType = ptUnknown
      end>
  end
  object quPedido: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'update Entradas set'
      '  PROVE = :PROVE,  PERENVREC = :PERENVREC,  STATUS = :STATUS,  '
      ' CONIVA = :CONIVA,  FECHA = :FECHA,  IMPORTE = :IMPORTE,'
      '  IVA = :IVA,  TOTAL = :TOTAL'
      'where'
      '  TIPO = :TIPO and  ALM = :ALM and'
      '  NUMERO = :NUMERO and  CIA = :CIA')
    Left = 152
    Top = 360
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'PROVE'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'PERENVREC'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'STATUS'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CONIVA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FECHA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'IMPORTE'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'IVA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'TOTAL'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'TIPO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ALM'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'NUMERO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
end
